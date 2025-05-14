#include <chrono>
#include <indicators/cursor_control.hpp>
#include <indicators/progress_bar.hpp>
#include <thread>

int main() {
  using namespace indicators;

  // Hide cursor
  show_console_cursor(false);

  ProgressBar bar{option::BarWidth{50},
                  option::Start{"["},
                  option::Fill{"■"},
                  option::Lead{"■"},
                  option::Remainder{"-"},
                  option::End{" ]"},
                  option::PostfixText{"Loading dependency 1/4"},
                  option::ForegroundColor{Color::cyan},
                  option::ShowElapsedTime{true},
                  option::ShowRemainingTime{true},
                  option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}};

  while (true) {
    bar.tick();
    if (bar.is_completed()) break;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}