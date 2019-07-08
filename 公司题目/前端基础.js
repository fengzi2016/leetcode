const mapObj = {
    "<":"&lt;",
    ">":"&gt;",
    "&":"&amp;",
    '\r':'\\\\r',
    '\n':'\\\\n',
    '\\': '\\\\\\\\\\', 
    '\"': '\\\\"',
    "'": "\\\\'"
}
const string = '<>&';
const escapeHTML1 =  (str) => (str.split('').map(s => (mapObj[s] ? mapObj[s] : s)).join(''));
console.log(escapeHTML1('<>&'));

const reg = new RegExp(Object.keys(mapObj).join('|'), 'gi');
const escapeHTML2 = (str) => (str.replace(reg, (match) => (mapObj[match])));
console.log(escapeHTML2("<>&\r\n\\\"'"));
// \\r\\n\\\\\\\"\\'

var url = "http://qzs.qq.com/test.htm?param=" + document.getElementById('theInput').value;
document.getElementById('link').innerHTML = "<a href='"+url+"'>"+url+"</a>";