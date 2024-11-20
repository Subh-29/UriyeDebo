
def hillClimbing(problem):
    current = problem.initialState()

    while True:
        neighbours = problem.getNeighbour(current)
        if not neighbours:
            return current
        next_state = max(neighbours, key=problem.evaluate)
        if problem.evaluate(next_state) <= problem.evaluate(current):
            return current
        current = next_state


class MaximisationProblem:
    def initialState(self):
        return 0
    
    def getNeighbour(self, state):
        return [state - 1, state + 1]
    
    def evaluate(self, state):
        return -state**3 + state * 4    #state = x, -x^3+4x
    
problem = MaximisationProblem()

solution = hillClimbing(problem)

print(f"{solution} is {problem.evaluate(solution)}")