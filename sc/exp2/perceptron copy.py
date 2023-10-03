import random
import csv
from random import shuffle


class Perceptron:
    def __init__(self, num_inputs, learning_rate=0.01):
        self.weights = [random.uniform(-1, 1) for _ in range(num_inputs)]
        self.bias = random.uniform(-1, 1)
        self.learning_rate = learning_rate

    def predict(self, inputs):
        weighted_sum = sum([inputs[i] * self.weights[i] for i in range(len(inputs))]) + self.bias
        return 1 if weighted_sum > 0 else 0

    def train(self, inputs, target):
        prediction = self.predict(inputs)
        error = target - prediction
        for i in range(len(self.weights)):
            self.weights[i] += self.learning_rate * error * inputs[i]
        self.bias += self.learning_rate * error



label_mapping = {"Apple": 1, "Banana": 0}  # Map labels to numeric values
feature_mapping = {"Round": 1, "Oval": 0, "Smooth": 1, "Rough": 0, "Light": 0, "Heavy": 1}


def load_training_data(filename):
    training_data = []

    with open(filename, 'r') as file:
        csv_reader = csv.reader(file)
        header = next(csv_reader)  # Read the header row
        for row in csv_reader:
            features = [feature_mapping[row[0]], feature_mapping[row[1]], feature_mapping[row[2]]]
            label = label_mapping.get(row[3], -1)  # Default to -1 for unknown labels
            if label != -1:
                training_data.append((features, label))
    return training_data


def main():
    # Define the perceptron for differentiating fruits
    num_inputs = 3  # Shape, Texture, Weight
    perceptron = Perceptron(num_inputs)

    # Load training data from CSV file
    training_data = load_training_data('training_data.csv')

    # Hyperparameters
    num_epochs = 10000

    for _ in range(num_epochs):
        # Shuffle the training data at the start of each epoch
        shuffle(training_data)

        for inputs, target in training_data:
            perceptron.train(inputs, target)

    # Testing the perceptron with words for test data
    test_data = [
        (["Round", "Rough", "Light"], "Unknown"),
        (["Oval", "Smooth", "Heavy"], "Unknown"),
        (["Round", "Smooth", "Heavy"], "Unknown"),
        (["Oval", "Rough", "Light"], "Unknown"),
    ]

    print("Results:")
    for inputs, _ in test_data:
        # Map words to 0 and 1
        mapped_inputs = [feature_mapping[feature] for feature in inputs]
        prediction = perceptron.predict(mapped_inputs)
        fruit_type = "Apple" if prediction == 1 else "Banana"
        print(f"Shape: {inputs[0]}, Texture: {inputs[1]}, Weight: {inputs[2]} => Predicted: {fruit_type}")

main()
