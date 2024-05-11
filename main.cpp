#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream> // Needed for stringstream

// Knowledge base
std::map<std::string, std::string> knowledgeBase;

// Tokenization function
std::vector<std::string> tokenize(const std::string& input) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// Inference engine
std::string generateResponse(const std::string& userInput) {
    // Tokenize user inpt
    std::vector<std::string> tokens = tokenize(userInput);

    // Search knowledge base
    for (auto& entry : knowledgeBase) {
        if (entry.first.find(tokens[0]) != std::string::npos) {
            return entry.second;
        }
    }

    // Return default response
    return "I didn't understand that.";
}

// Learning module
void updateKnowledgeBase(const std::string& userInput, const std::string& response) {
    // Update knowledge base with new information
    knowledgeBase[userInput] = response;
}

int main() {
    // Initialize knowledge base
    knowledgeBase["hello"] = "Hi! How can I help you?";
    knowledgeBase["goodbye"] = "Goodbye! See you later.";
    knowledgeBase["Atishay"] = "Atishay! I Love You.";
    knowledgeBase["Baby"] = "Baby! Said Atishay I Like You.";


    // Chatbot loop
    while (true) {
        std::string userInput;
        std::cout << "You: ";
        std::getline(std::cin, userInput);

        std::string response = generateResponse(userInput);
        std::cout << "Chatbot: " << response << std::endl;

        // Update knowledge base
        updateKnowledgeBase(userInput, response);
    }
    return 0;
}