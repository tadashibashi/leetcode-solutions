/**
 * @param {Function} fn
 * @param {Array} args
 * @param {number} t
 * @return {Function}
 */
var cancellable = function(fn, args, t) {
    // immediate call
    fn(...args);

    // call every t milliseconds
    let interval = setInterval(() => fn(...args), t);

    // return cancel function
    return function() {
        if (interval) {
            clearInterval(interval);
            interval = null;
        }
    };
};
