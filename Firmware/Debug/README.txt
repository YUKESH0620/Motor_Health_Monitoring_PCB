# Debug Module

This folder is reserved for firmware debug utilities such as:

- UART-based logging
- Diagnostic command handlers
- Manufacturing test hooks
- Temporary instrumentation

In the current firmware version:
- Debug output is intentionally minimal
- UART is used only for control commands
- No continuous logging is enabled to reduce overhead

This folder exists to preserve a clean firmware architecture
and to allow future debug expansion without restructuring.
