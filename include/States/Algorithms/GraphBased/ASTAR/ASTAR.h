#pragma once

// Same structure as Dijkstra in a  way
#include <queue>

#include "States/Algorithms/GraphBased/BFS/BFS.h"
#include "States/Algorithms/GraphBased/Utils.h"

namespace visualizer {
namespace graph_based {

struct MinimumDistanceASTAR {
  // operator overloading
  bool operator()(const std::shared_ptr<Node> &n1,
                  const std::shared_ptr<Node> &n2) const {
    return n1->getFDistance() > n2->getFDistance();
  }
};

class ASTAR : public BFS {
 public:
  // Constructor
  ASTAR(std::shared_ptr<gui::LoggerPanel> logger_panel);

  // Destructor
  virtual ~ASTAR();

  // override initialization Functions
  void initAlgorithm() override;

  // override main update function
  virtual void updatePlanner(bool &solved, Node &start_node,
                             Node &end_node) override;

 private:
  // STOP FORMATTING TO A NEW LINE JESUS FUCKING CHRIST
  std::priority_queue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>,
                      MinimumDistanceASTAR>
      frontier_;
  bool use_mhh{true};
};

}  // namespace graph_based
}  // namespace visualizer