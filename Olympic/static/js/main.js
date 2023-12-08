document.getElementById('login-button').addEventListener('click', function() {
    var username = document.getElementById('username').value;
    var password = document.getElementById('password').value;
    
    // Here you would validate the username and password.
    // For now, we just simulate successful login.
    if (username === 'admin' && password === 'RiddleThisR1dd13Th4T') { // replace with actual validation
        document.getElementById('login-container').classList.add('hidden');
        document.getElementById('terminal-container').classList.remove('hidden');
        document.getElementById('terminal-input').focus();
    } else {
        alert('Invalid credentials');
    }
});

document.getElementById('terminal-input').addEventListener('keydown', function(e) {
    if (e.key === 'Enter') {
        var command = this.value;
        this.value = '';

        // Display the entered text in the terminal
        var terminal = document.getElementById('terminal');
        terminal.value += '\n$ ' + command;
        terminal.scrollTop = terminal.scrollHeight;

        // Check for the reset state command
        if (command.toLowerCase() === 'reset state') {
            // Send command to server to reset the state
            fetch('/reset-state', {
                method: 'POST',
                // Additional options like headers, body, etc.
            })
                .then(response => response.text())
                .then((response) => {
                    terminal.value += '\n' + response;
                    terminal.scrollTop = terminal.scrollHeight;
                })
                .catch(error => console.error('Error:', error));
        }
        // Check for the special command to open a new tab
        else if (command === 'start "Olympic.exe"') {
            window.open('/landing', '_blank'); // Opens a new tab with the game interface
        }
        // All other inputs are displayed as they are without any error or special handling
    }
});



// Function to toggle terminal position
function toggleTerminalPosition() {
    var terminalContainer = document.getElementById('terminal-container');
    if (terminalContainer.classList.contains('bottom-left-terminal')) {
        terminalContainer.classList.remove('bottom-left-terminal');
        terminalContainer.classList.add('underneath-input');
    } else {
        terminalContainer.classList.remove('underneath-input');
        terminalContainer.classList.add('bottom-left-terminal');
    }
}

// You can call this function to toggle between the two styles
// For example, you could have a button that when clicked calls this function
document.getElementById('toggle-button').addEventListener('click', toggleTerminalPosition);

// ...existing JavaScript...

// Function to change text color
function changeTextColor(color) {
    var terminalContainer = document.getElementById('terminal-container');
    var loginContainer = document.getElementById('login-container');
    
    // Remove existing color classes from both containers
    terminalContainer.classList.remove('white-text', 'vibrant-purple-text', 'vibrant-green-text');
    loginContainer.classList.remove('white-text', 'vibrant-purple-text', 'vibrant-green-text');
    
    // Add the selected color class to both containers
    if (color === 'white') {
        terminalContainer.classList.add('white-text');
        loginContainer.classList.add('white-text');
    } else if (color === 'purple') {
        terminalContainer.classList.add('vibrant-purple-text');
        loginContainer.classList.add('vibrant-purple-text');
    } else if (color === 'green') {
        terminalContainer.classList.add('vibrant-green-text');
        loginContainer.classList.add('vibrant-green-text');
    }
}

// Event listeners for color change buttons
document.getElementById('color-white-button').addEventListener('click', function() {
    changeTextColor('white');
});

document.getElementById('color-purple-button').addEventListener('click', function() {
    changeTextColor('purple');
});

document.getElementById('color-green-button').addEventListener('click', function() {
    changeTextColor('green');
});


