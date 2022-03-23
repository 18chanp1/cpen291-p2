<template>
  <img alt="Vue logo" src="./assets/logo.png">
  <HelloWorld msg="Welcome to Your Vue.js AppTwo"/>
</template>

<script>
import HelloWorld from './components/HelloWorld.vue'

export default {
  name: 'AppTwo',
  components: {
    HelloWorld
  }
}
</script>

<style>
#appTwo {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
