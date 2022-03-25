<template>
  <div class = "container">
    <hdr_bar title = "myTitle" />
    <hdr_bar title = "test" />
    <text_entry></text_entry>

  </div>
</template>

<script>
  import hdr_bar from '/src/components/hdr_bar.vue'
  import text_entry from '/src/components/text_entry.vue'

  export default {
    name:'App',
    components: {
      hdr_bar,
      text_entry,
    }
  }
</script>
