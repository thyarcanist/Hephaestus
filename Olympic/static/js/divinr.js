document.addEventListener('DOMContentLoaded', () => {
    const followButtons = document.querySelectorAll('.follow-btn');

    followButtons.forEach(btn => {
        btn.addEventListener('click', (e) => {
            const godName = e.target.previousElementSibling.innerText;
            alert(`You are now following ${godName}`);
        });
    });
});

document.addEventListener('DOMContentLoaded', () => {
    // Add event listeners for like, love, and praise buttons
    const likeButtons = document.querySelectorAll('.like-btn');
    likeButtons.forEach(btn => {
        btn.addEventListener('click', () => {
            // Implement like functionality or increment count
            alert('Liked!');
        });
    });

    // Repeat for love and praise buttons
});

