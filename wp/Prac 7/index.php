<!DOCTYPE html>
<html>
<head>
	<title>Submitted Form Data</title>
</head>
<body>
	<?php if ($_SERVER["REQUEST_METHOD"] == "POST"): ?>
		<h2>Form Data Submitted Successfully!</h2>
		<p><strong>Name:</strong> <?php echo $_POST["name"]; ?></p>
		<p><strong>Email:</strong> <?php echo $_POST["email"]; ?></p>
		<p><strong>Message:</strong> <?php echo $_POST["message"]; ?></p>
	<?php else: ?>
		<h2>Error: Form Data Not Submitted</h2>
	<?php endif; ?>
</body>
</html>
