const sqlite3 = require("sqlite3").verbose();
const cors = require("cors");
const express = require("express");
const bodyParser = require("body-parser");
const app = express();
const cookieParser = require("cookie-parser");

const PORT = process.env.PORT || 5001;
const SECRET = "mysecret";

app.use(bodyParser.json());
app.use(cookieParser());
app.use(cors());

const db = new sqlite3.Database("itldb.sqlite");

const Sequelize = require("sequelize");
const sequelize = new Sequelize({
  dialect: "sqlite",
  storage: "itldb.sqlite",
});

const User = sequelize.define("User", {
  id: {
    type: Sequelize.INTEGER,
    primaryKey: true,
    autoIncrement: true,
  },
  email: {
    type: Sequelize.STRING,
    allowNull: false,
    unique: true,
  },
  password: {
    type: Sequelize.STRING,
    allowNull: false,
  },
  name: {
    type: Sequelize.STRING,
    allowNull: false,
  },
});

sequelize.sync();

const jwt = require("jsonwebtoken");

app.post("/api/create-user", async (req, res) => {
  const { email, password, name } = req.body;

  const user = await User.create({ email, password, name });

  const token = jwt.sign({ email, id: user.id }, SECRET);

  res.cookie("token", token);

  res.send({ message: "User created successfully" });
});

app.post("/api/login", async (req, res) => {
  const { email, password } = req.body;

  const user = await User.findOne({ where: { email, password } });

  if (!user) {
    return res.status(401).send({ message: "Invalid email or password" });
  }

  const token = jwt.sign({ email, id: user.id }, SECRET);

  res.cookie("token", token);

  res.send({ message: "Logged in successfully" });
});

app.get("/api/authenticated", async (req, res) => {
  const token = req.cookies?.token;
  if (!token)
    if (!token) {
      return res.status(401).send({ message: "Unauthorized" });
    }

  try {
    const decoded = jwt.verify(token, SECRET);

    const user = await User.findOne({
      where: { email: decoded.email, id: decoded.id },
    });

    if (!user) {
      return res.status(401).send({ message: "Unauthorized" });
    }

    res.send({ message: "Authenticated", user });
  } catch (err) {
    return res.status(401).send({ message: "Unauthorized" });
  }
});

app.post("/api/myposts",  async (req, res) => {
  const token = req.cookies?.token;
  if (!token)
    if (!token) {
      return res.status(401).send({ message: "Unauthorized" });
    }

  try {
    const decoded = jwt.verify(token, SECRET);

    const user = await User.findOne({
      where: { email: decoded.email, id: decoded.id },
    });

    if (!user) {
      return res.status(401).send({ message: "Unauthorized" });
    }

    res.send({ message: "Authenticated", user });
  } catch (err) {
    return res.status(401).send({ message: "Unauthorized" });
  }
});

app.get("/api/myposts", (req, res) => {
  res.send({
    message: "Unauthenticated response :)",
    posts: [
      { title: "latest post", description: "post desc" },
      { title: "second latest post", description: "second post desc" },
    ],
  });
});

// Start the server
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
