#include "DIJKSTRA.h"

namespace visualizer {
namespace graph_based {

// Constructor
DIJKSTRA::DIJKSTRA(std::shared_ptr<gui::LoggerPanel> logger_panel)
    : BFS(logger_panel) {}

// Destructor
DIJKSTRA::~DIJKSTRA() {}

// override initAlgorithm() function
void DIJKSTRA::initAlgorithm() {
  while (!frontier_.empty()) {
    frontier_.pop();
  }
  // Distance init
  /**
   * @note: Here  for Astar do the heuristic calculation based on the grid mode.
   * Grid mode unhandled could fuck it up here.
   */
  nodeStart_->setGDistance(0.0);
  frontier_.push(nodeStart_);
}

void DIJKSTRA::updatePlanner(bool &solved, Node &start_node, Node &end_node) {
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

      auto distance = nc->getGDistance() + utils::distanceCost(*nc, *nn);
      if (distance < nn->getGDistance()) {
        nn->setParentNode(nc);
        nn->setGDistance(distance);
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