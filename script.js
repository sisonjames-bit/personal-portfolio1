// Responsive Menu Toggle
const menuToggle = document.getElementById("menu-toggle");
const navLinks = document.getElementById("nav-links");

menuToggle.addEventListener("click", () => {
  navLinks.classList.toggle("active");
});

// Simple contact form handler
function handleSubmit(event) {
  event.preventDefault();
  alert("Thank you for reaching out! Your message has been sent successfully.");
  event.target.reset();
}
