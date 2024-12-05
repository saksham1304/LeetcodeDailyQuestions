class Solution {
public:
    string simplifyPath(string path) {
        
        std::stack<std::string> stack;
std::stringstream ss(path);
std::string item;

while (std::getline(ss, item, '/')) {
    if (item == "..") {
        if (!stack.empty()) {
            stack.pop();
        }
    } else if (!item.empty() && item != "." && item != "..") {
        stack.push(item);
    }
}

std::string simplifiedPath;
while (!stack.empty()) {
    simplifiedPath = "/" + stack.top() + simplifiedPath;
    stack.pop();
}

return simplifiedPath.empty() ? "/" : simplifiedPath;

    }
};