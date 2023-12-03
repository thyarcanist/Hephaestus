document.addEventListener('DOMContentLoaded', () => {
    const followButtons = document.querySelectorAll('.follow-btn');

    followButtons.forEach(btn => {
        btn.addEventListener('click', (e) => {
            const godName = e.target.previousElementSibling.innerText;
            alert(`You are now following ${godName}`);
        });
    });
});
