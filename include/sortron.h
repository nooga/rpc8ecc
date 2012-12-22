// sortron.h

// SORTRON DOCUMENTATION

// Addresses
// $00: Command
//   Set to $FF upon error
//   Set to not $FF (presumably $00) upon success
//   $01: read number of slots
//     returns number of inventory slots in $02
//   $02: read slot
//     slot number in $02,
//     returns info about item slot
//   $03: pull items
//     slot number in $02, count in $01, output color in $0C
//   $04: match items on input
//     number of items in $01, hash in $04, color in $0D,
//     only returns success when match is complete

// $01: number of items in slot

// $02-$03: slot to operate on

// $04-$07: item hash

// $08-$09: item damage

// $0A-$0B: maximum item damage

// $0C: output color
//   0 is none, 1-16 is white-black

// $0D: input color