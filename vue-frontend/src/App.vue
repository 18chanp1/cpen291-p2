<template>
  <div class = "container">
    <hdr_bar title = "myTitle" />
    <hdr_bar title = "test" />
    <text_entry></text_entry>

  </div>
</template>

<script>
import hdr_bar from './components/hdr_bar.vue'
import text_entry from './components/text_entry.vue'


export default{
  name:'App',
  components: {
    hdr_bar,
    text_entry,
}
}
</script>

<style>
#app {
  font-family: Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: left;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
