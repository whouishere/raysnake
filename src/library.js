addToLibrary({
  /**
   * reads and returns the high score from the browser cache
   * @returns {number}
   */
  readHighScore: function() {
    let score = localStorage.getItem('score') || '0';
    return Number(score);
  },

  /**
   * saves high score to browser cache
   * @param {number} score value to save to high score cache
   */
  saveHighScore: function(score) {
    localStorage.setItem('score', score);
  },
});
