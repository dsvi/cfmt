#include <array>
#include <string>
#include <thread>
#include "cfmt.h"

using namespace std;

int main()
{
	auto colors = to_array<tuple<string, string>>({
		{"black","bk"},
		{"red","r"},
		{"green","g"},
		{"yellow","y"},
		{"blue","b"},
		{"magenta","m"},
		{"cyan","c"},
		{"white","w"},
		{"bright black","bbk"},
		{"bright red","br"},
		{"bright green","bg"},
		{"bright yellow","by"},
		{"bright blue","bb"},
		{"bright magenta","bm"},
		{"bright cyan","bc"},
		{"bright white","bw"},
	});
	for (const auto &c : colors){
		string name, code;
		tie(name, code) = c;
		cfmt::cprint("{f"+code+"}Hello! {fd}{b"+code+"}      {bd} {}\n", name);
	}
	auto styles = to_array<tuple<string, string>>({
		{"italic",     "i"},
		{"bold",       "b"},
		{"underline",  "u"},
		{"strike",     "s"},
		{"pulsating",  "p"},
		{"reversed",   "r"},
	});
	for (const auto &s : styles){
		string name, code;
		tie(name, code) = s;
		cfmt::cprint("{"+code+"}{}{n"+code+"}\n", name);
	}
	cfmt::cprint("{i}{u}{b}{p}{r}all at once\n");
	cfmt::cprint("{d}");
	for (int i = 0; i < 100; ++i) {
		std::this_thread::sleep_for(500ms);
		cfmt::cprint("{}%\n", i);
		cfmt::move_up();
	}
	return 0;
}
