import random

class Individual:
    def __init__(self, chromosome):
        self.chromosome = chromosome
        self.fitness = self.calculate_fitness()

    @classmethod
    def create_random_gene(cls):
        return random.choice(GENES)

    @classmethod
    def create_random_chromosome(cls, length):
        return [cls.create_random_gene() for _ in range(length)]

    @classmethod
    def crossover(cls, gene1, gene2):
        return gene1 if random.random() < 0.45 else gene2 if random.random() < 0.90 else cls.create_random_gene()

    def mate(self, partner):
        child_chromosome = [self.crossover(gene1, gene2) for gene1, gene2 in zip(self.chromosome, partner.chromosome)]
        return Individual(child_chromosome)

    def calculate_fitness(self):
        return sum(gene != target_gene for gene, target_gene in zip(self.chromosome, TARGET))

class GeneticAlgorithm:
    def __init__(self, population_size):
        self.population_size = population_size
        self.population = [Individual(Individual.create_random_chromosome(len(TARGET))) for _ in range(population_size)]
        self.generation = 1

    def evolve(self):
        while not self.is_target_reached():
            self.population.sort(key=lambda x: x.fitness)
            self.display_generation_info()

            new_generation = self.select_fittest()

            for _ in range(self.get_offspring_count()):
                parent1 = random.choice(self.population[:50])
                parent2 = random.choice(self.population[:50])
                child = parent1.mate(parent2)
                new_generation.append(child)

            self.population = new_generation
            self.generation += 1

    def is_target_reached(self):
        return any(individual.fitness <= 0 for individual in self.population)

    def select_fittest(self):
        return self.population[:int(0.10 * self.population_size)]

    def get_offspring_count(self):
        return int(0.90 * self.population_size)

    def display_generation_info(self):
        best_individual = self.population[0]
        print(f"Generation: {self.generation} \tString: {''.join(best_individual.chromosome)} \tFitness: {best_individual.fitness}")

if __name__ == '__main__':
    POPULATION_SIZE = 100
    GENES = '''abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 1234567890, .-;:_!"#%&/()=?@${[]}'''
    TARGET = "Welcome to SPIT folks"

    genetic_algorithm = GeneticAlgorithm(POPULATION_SIZE)
    genetic_algorithm.evolve()
