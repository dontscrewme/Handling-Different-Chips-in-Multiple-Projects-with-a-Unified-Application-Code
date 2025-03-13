# Handling-Different-Chips-in-Multiple-Projects-with-a-Unified-Application-Code


When developing applications that interface with hardware, it's common to work with different chips that serve the same purpose but have different internal implementations. This can lead to the challenge of managing different chip modules while maintaining a consistent application code across multiple projects. This post will walk you through how to handle such situations and provide a solution that allows the same application code to work with different chips.

In many embedded systems, we may have different chips from different vendors that provide similar functionality. However, each chip may expose different APIs or require different initialization procedures. If the project involves multiple chips, the application code may become messy and difficult to maintain. The goal is to design the application such that the same logic can be used regardless of the chip used, abstracting the chip-specific details.

The solution

1. Using Conditional Compilation
One effective way to handle this scenario is to use conditional compilation. By using preprocessor directives, we can select which chip to use at compile time, ensuring that the application code stays consistent and simple.

 
