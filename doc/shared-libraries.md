Shared Libraries
================

## CI AI COINconsensus

The purpose of this library is to make the verification functionality that is critical to CI AI COIN's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `CI AI COINconsensus.h` located in `src/script/CI AI COINconsensus.h`.

#### Version

`CI AI COINconsensus_version` returns an `unsigned int` with the API version *(currently `1`)*.

#### Script Validation

`CI AI COINconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `CI AI COINconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `CI AI COINconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `CI AI COINconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/CI AI COIN/bips/blob/master/bip-0016.mediawiki)) subscripts
- `CI AI COINconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/CI AI COIN/bips/blob/master/bip-0066.mediawiki)) compliance
- `CI AI COINconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/CI AI COIN/bips/blob/master/bip-0147.mediawiki))
- `CI AI COINconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/CI AI COIN/bips/blob/master/bip-0065.mediawiki))
- `CI AI COINconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/CI AI COIN/bips/blob/master/bip-0112.mediawiki))
- `CI AI COINconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/CI AI COIN/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `CI AI COINconsensus_ERR_OK` - No errors with input parameters *(see the return value of `CI AI COINconsensus_verify_script` for the verification status)*
- `CI AI COINconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `CI AI COINconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `CI AI COINconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `CI AI COINconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NCI AI COIN](https://github.com/NicolasDorier/NCI AI COIN/blob/master/NCI AI COIN/Script.cs#L814) (.NET Bindings)
- [node-libCI AI COINconsensus](https://github.com/bitpay/node-libCI AI COINconsensus) (Node.js Bindings)
- [java-libCI AI COINconsensus](https://github.com/dexX7/java-libCI AI COINconsensus) (Java Bindings)
- [CI AI COINconsensus-php](https://github.com/Bit-Wasp/CI AI COINconsensus-php) (PHP Bindings)
