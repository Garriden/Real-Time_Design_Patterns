#include "LowPass.h"
#include "Pipe.h"
#include "Display.h"
#include "Generator.h"

#include <iostream>

#include <thread> 
#include <chrono>         // namespace chrono
#include <future>
#include <random>

using namespace std;
using namespace chrono;
using namespace chrono_literals;


static std::random_device rd;  //Will be used to obtain a seed for the random number engine
static std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
static std::uniform_int_distribution<> dist(1, 10);

LowPass::LowPass(Generator& g, Display& d, Event::Type ty):
generator{ &g },
display{ &d },
filter_level { ty }
{

}

int LowPass::operator()()
{
    // auto event = generator->generate_event(); // sync-blocking call
    auto result = async(*generator);
    int count { dist(gen)};
    for(int i = 0; i < count; ++i) {
        this_thread::sleep_for(100ms);
        cout << '.' << flush;
    }
    auto event = result.get();
    if( static_cast<int>(event->type()) >= static_cast<int>(filter_level)) {
        display->show(*event);
    }
    return 0;
}

void LowPass::process(Event& ev)
{
    input.push(make_unique<Event>(ev));
}


#ifdef TDD
#include "doctest.h"
#include <memory>

// TEST_CASE("Initial LowPass") {
//     Pipe      in{};
//     Pipe      out{};
//     LowPass lp{in, out};
//     auto rv = lp();
//     CHECK( rv == -1);
// }

// TEST_CASE("LowPass push-pull") {
//     Pipe      pipe1{};
//     Pipe      pipe2{};
//     LowPass lp{pipe1, pipe2};
//     pipe1.push(std::make_unique<Event>(Event::Type::WARNING));
//     auto rv = lp();
//     CHECK( rv != -1);
//     auto e{ pipe2.pull() };
//     CHECK(e->type() == Event::Type::WARNING);
// }

// TEST_CASE("LowPass filter") {
//     Pipe      pipe1{};
//     Pipe      pipe2{};
//     LowPass lp{pipe1, pipe2, Event::Type::CAUTION};
//     pipe1.push(std::make_unique<Event>(Event::Type::WARNING));
//     auto rv = lp();
//     CHECK( rv == -1);
//     auto e{ pipe2.pull() };
//     CHECK(e == nullptr);
// }

#endif
