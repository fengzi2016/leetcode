class EventEmitter {
  constructor() {
    this.events = {};
  }
  on(eventName,func){
    if(!this.events[eventName]){
      this.events[eventName] = [];
    }
    this.events[eventName].push(func);
  }
  emit(eventName,...args){
    if(!this.events[eventName]) return;
    const callbacks = this.events[eventName];
    callbacks.forEach((fn)=>{
      fn(args);
    });
  }
  off(eventName,func){
    if(!this.events[eventName]) return;
    const callbacks = this.events[eventName];
    let index = callbacks.indexof(func);
    callbacks.splice(index,1);
  }
}
