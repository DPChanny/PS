#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> _names, vector<string> _reports, int _k) {
    map<string, vector<string>> reports;
    map<string, int> report_counts;
    for (size_t _report(0); _report < _reports.size(); _report++) {
        string
            from = _reports[_report].substr(0, _reports[_report].find(' ')),
            to = _reports[_report].substr(_reports[_report].find(' '));
        if (find(reports[from].begin(), reports[from].end(), to) == reports[from].end()) {
            reports[from].push_back(to);
            report_counts[to]++;
        }
    }
    vector<int> result(_names.size());
    for (size_t _name(0); _name < _names.size(); _name++)
        for (size_t _report(0); _report < reports[_names[_name]].size(); _report++)
            if (report_counts[reports[_names[_name]][_report]] + 1 > _k) result[_name]++;
    return result;
}