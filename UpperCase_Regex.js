function myTag(strings, ...values) {
  return `${strings[0]}${values[0].toUpperCase()}${strings[1]}`;
}
const str = myTag`Hello ${"world"}`;
console.log(str);
