import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import StandardScaler, OrdinalEncoder, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix
import seaborn as sns
import matplotlib.pyplot as plt

# %matplotlib inline

# Load your dataset
# Replace 'your_dataset.csv' with the actual file path or URL
data = pd.read_csv('logistic/social.csv')

# Specify the columns for features (X) and target variable (y)
# Replace 'feature_columns' and 'target_column' with your actual column names
feature_columns = ['Gender', 'Age', 'EstimatedSalary']
target_column = 'Purchased'

# Specify columns that require ordinal encoding (if any)
ordinal_columns = []

# Specify columns that require one-hot encoding (if any)
one_hot_columns = ['Gender']

# Separate features and target variable
X = data[feature_columns]
y = data[target_column]

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Create transformers for ordinal and one-hot encoding
# Add more transformers as needed
preprocessor = ColumnTransformer(
    transformers=[
        ('ordinal', OrdinalEncoder(), ordinal_columns),
        ('onehot', OneHotEncoder(), one_hot_columns)
    ],
    remainder='passthrough'  # pass through the columns not specified for encoding
)

# Create a logistic regression model
model = LogisticRegression()

# Create a pipeline that first applies preprocessing and then fits the model
pipeline = Pipeline(steps=[('preprocessor', preprocessor),
                           ('model', model)])

# Fit the model to the training data
pipeline.fit(X_train, y_train)

# Make predictions on the test data
y_pred = pipeline.predict(X_test)

# Evaluate the model
accuracy = accuracy_score(y_test, y_pred)
precision = precision_score(y_test, y_pred)
recall = recall_score(y_test, y_pred)
f1 = f1_score(y_test, y_pred)
conf_matrix = confusion_matrix(y_test, y_pred)

print(f'Accuracy: {accuracy}')
print(f'Precision: {precision}')
print(f'Recall: {recall}')
print(f'F1 Score: {f1}')
print(f'Confusion Matrix:\n{conf_matrix}')

# Plot the confusion matrix
plt.figure(figsize=(8, 6))
sns.heatmap(conf_matrix, annot=True, fmt='d', cmap='Blues', cbar=False,
            xticklabels=['Predicted 0', 'Predicted 1'],
            yticklabels=['Actual 0', 'Actual 1'])
plt.xlabel('Predicted Label')
plt.ylabel('True Label')
plt.title('Confusion Matrix')
plt.show()

# Now you can use the trained model for predictions on new data
# For example: pipeline.predict(new_data)
