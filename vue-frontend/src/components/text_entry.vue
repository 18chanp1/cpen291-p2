<template>
    <input v-model="text_input" placeholder="Type here">
    <p>{{ text_input }}</p>
</template>

<script>
export default {
  data() {
    return {
      text_input: ''
    }
  }
}
</script>