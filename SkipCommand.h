#pragma once
#include <string>

class GameManager;

/**
 * Command Pattern: The Command interface.
 * Encapsulates a skip reward request as an object.
 */
class SkipCommand {
public:
    virtual ~SkipCommand() = default;
    virtual std::string getDescription() const = 0;
    
    // The execute method triggers the command on the receiver (GameManager)
    virtual void execute(GameManager& gm) = 0;
};
