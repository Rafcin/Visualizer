#include "ASTAR.h"

namespace visualizer {
namespace graph_based {

// Constructor
ASTAR::ASTAR(std::shared_ptr<gui::LoggerPanel> logger_panel)
    : BFS(logger_panel) {}

// Destructor
ASTAR::~ASTAR() {}

// override initAlgorithm() function
void ASTAR::initAlgorithm() {
  while (!frontier_.empty()) {
    frontier_.pop();
  }
  // Grid type check and heuristic calculation.
  use_mhh = grid_connectivity_ == 0 ? true : false;
  nodeStart_->setGDistance(0.0);
  nodeStart_->setFDistance(
      utils::costToGoHeuristics(*nodeStart_, *nodeEnd_, use_mhh));
  frontier_.push(nodeStart_);
}

void ASTAR::updatePlanner(bool &solved, Node &start_node, Node &end_node) {
  if (!frontier_.empty()) {
    std::shared_ptr<Node> nc = frontier_.top();
    nc->setFrontier(false);
    nc->setVisited(true);
    frontier_.pop();

    if (nc->isGoal()) {
      solved = true;
    };

    for (auto nn : *nc->getNeighbours()) {
      if (nn->isVisited() || nn->isObstacle()) {
        continue;
      }

      auto distance =
          nc->getGDistance() + utils::costToGoHeuristics(*nc, *nn, use_mhh);
      if (distance < nn->getGDistance()) {
        nn->setParentNode(nc);
        nn->setGDistance(distance);
        // Ref - https://brilliant.org/wiki/a-star-search/
        auto f = nc->getGDistance() +
                 utils::costToGoHeuristics(*nc, end_node, use_mhh);
        nn->setFDistance(f);
        nn->setFrontier(true);
        frontier_.push(nn);
      }
    }
  } else {
    solved = true;
  }
}

}  // namespace graph_based
}  // namespace visualizer