#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

#define MAX_LINE_LENGTH 1000

typedef struct {
    std::string date;
    int count;
} Entry;

bool compare(const Entry &a, const Entry &b) {
    return a.date < b.date;
}

int main() {
    std::unordered_map<std::string, int> date_to_count;
    std::vector<Entry> entries;

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line[0] == '*') {
            break;
        }

        std::string date = line.substr(0, 10);
        date_to_count[date]++;
    }

    for (const auto &pair : date_to_count) {
        entries.push_back({pair.first, pair.second});
    }

    std::sort(entries.begin(), entries.end(), compare);

    for (const auto &entry : entries) {
        std::cout << entry.date << " " << entry.count << "\n";
    }

    return 0;
}
