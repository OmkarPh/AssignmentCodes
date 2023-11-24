import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import StandardScaler, OrdinalEncoder, OneHotEncoder
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.metrics import mean_squared_error, mean_absolute_error, r2_score

# Load your dataset
# Replace 'your_dataset.csv' with the actual file path or URL
data = pd.read_csv('your_dataset.csv')

# Specify the columns for features (X) and target variable (y)
# Replace 'feature_columns' and 'target_column' with your actual column names
feature_columns = ['feature1', 'feature2', 'feature3']
target_column = 'target'

# Specify columns that require ordinal encoding (if any)
ordinal_columns = ['ordinal_feature']

# Specify columns that require one-hot encoding (if any)
one_hot_columns = ['categorical_feature']

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

# Create a linear regression model
model = LinearRegression()

# Create a pipeline that first applies preprocessing and then fits the model
pipeline = Pipeline(steps=[('preprocessor', preprocessor),
                           ('model', model)])

# Fit the model to the training data
pipeline.fit(X_train, y_train)

# Make predictions on the test data
y_pred = pipeline.predict(X_test)

# Evaluate the model
mse = mean_squared_error(y_test, y_pred)
mae = mean_absolute_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

sse = ((y_test - y_pred) ** 2).sum()
sst = ((y_test - y_test.mean()) ** 2).sum()
rmse = mean_squared_error(y_test, y_pred, squared=False)  # square root of MSE
mst = sst / len(y_test)  # mean squared total

print(f'Mean Squared Error (MSE): {mse}')
print(f'Mean Absolute Error (MAE): {mae}')
print(f'R-squared (R2) Score: {r2}')
print(f'Sum of Squared Errors (SSE): {sse}')
print(f'Sum of Squared Total (SST): {sst}')
print(f'Mean Squared Total (MST): {mst}')
print(f'Root Mean Squared Error (RMSE): {rmse}')