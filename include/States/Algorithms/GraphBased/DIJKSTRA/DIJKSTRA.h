#pragma once

#include <queue>

#include "States/Algorithms/GraphBased/BFS/BFS.h"
#include "States/Algorithms/GraphBased/Utils.h"

namespace visualizer {
namespace graph_based {

struct MinimumDistanceDIJKSTRA {
  bool operator()(const std::shared_ptr<Node> &n1,
                  const std::shared_ptr<Node> &n2) const {
    return n1->getGDistance() > n2->getGDistance();
  }
};

class DIJKSTRA : public BFS {
 public:
  // Constructor
  DIJKSTRA(std::shared_ptr<gui::LoggerPanel> logger_panel);

  // Destructor
  virtual ~DIJKSTRA();

  // override initialization Functions
  void initAlgorithm() override;

  // override main update function
  virtual void updatePlanner(bool &solved, Node &start_node,
                             Node &end_node) override;

 private:
  std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>,
                      MinimumDistanceDIJKSTRA>
      frontier_;
};

}  // namespace graph_based
}  // namespace visualizer