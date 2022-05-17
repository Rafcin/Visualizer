#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

#include "State.h"

namespace visualizer {

//Define your planners here for the dropdown.
static const std::vector<std::string> GRAPH_BASED_PLANNERS{"BFS", "DFS"};
enum GRAPH_BASED_PLANNERS_IDS { BFS, DFS };

class Game {
 public:
  // Constructors
  Game(sf::RenderWindow* window, sf::RenderTexture* render_texture);

  // Destructors
  virtual ~Game();

  // Accessors
  const bool running() const;

  // Functions
  void pollEvents();
  void updateDt();
  void update();
  void render();
  void initGuiTheme();
  void renderNewPlannerMenu();
  void renderRunMenu(ImGuiIO& io);
  void setGraphBasedPlanner(const int id);
  void showHowToUseWindow();
  void showAboutWindow();

 private:
  sf::RenderWindow* window_;
  sf::RenderTexture* render_texture_;
  sf::Vector2f view_move_xy_;
  ImVec2 mouse_pos_in_canvas_;
  sf::Event ev_;
  sf::Clock dtClock_;
  float dt_;
  //Planners stack
  std::stack<std::unique_ptr<State>> states_;
  std::string curr_planner_;
  std::shared_ptr<gui::LoggerPanel> logger_panel_;
  bool disable_run_;
  bool show_how_to_use_window_{true};
  bool show_about_window_{true};
  bool show_control_panel_{true};
  bool show_console_{true};
  bool show_stats_panel_{true};
};

}  // namespace visualizer