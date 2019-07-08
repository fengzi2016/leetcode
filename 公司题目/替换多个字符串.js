const map = {
    '<': '&tl;',
    '>': '&gl;',
    '&': '&amp;'
}
const reg = new RegExp(Object.keys(map).join('|'), 'gi');
const escapeHTML = (str) => (str.replace(reg, (match) => (map[match])));