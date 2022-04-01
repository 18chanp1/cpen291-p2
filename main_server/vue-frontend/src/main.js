import { createApp } from 'vue'
import App from './App.vue'
import router from './router'
import VueCookies from 'vue-cookies'


createApp(App).use(router, VueCookies).mount('#app')


//initializes cookies on first page entry so all stats are 0. 

if(!window.$cookies.isKey('A')){
    for(var p = 0; p < 26; p++){
      window.$cookies.set(String.fromCharCode(65 + p), 0)
    }
    window.$cookies.set('Mario', '0')
    window.$cookies.set('RickRoll', '0')
    window.$cookies.set('GoukurakuJoudo', '0')
    window.$cookies.set('sum', '0')
    window.$cookies.set('songsz', '0')
}