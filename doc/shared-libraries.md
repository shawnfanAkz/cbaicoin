Shared Libraries
================

## CB AI COINconsensus

The purpose of this library is to make the verification functionality that is critical to CB AI COIN's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `CB AI COINconsensus.h` located in `src/script/CB AI COINconsensus.h`.

#### Version

`CB AI COINconsensus_version` returns an `unsigned int` with the API version *(currently `1`)*.

#### Script Validation

`CB AI COINconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `CB AI COINconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `CB AI COINconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `CB AI COINconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/CB AI COIN/bips/blob/master/bip-0016.mediawiki)) subscripts
- `CB AI COINconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/CB AI COIN/bips/blob/master/bip-0066.mediawiki)) compliance
- `CB AI COINconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/CB AI COIN/bips/blob/master/bip-0147.mediawiki))
- `CB AI COINconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/CB AI COIN/bips/blob/master/bip-0065.mediawiki))
- `CB AI COINconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/CB AI COIN/bips/blob/master/bip-0112.mediawiki))
- `CB AI COINconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/CB AI COIN/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `CB AI COINconsensus_ERR_OK` - No errors with input parameters *(see the return value of `CB AI COINconsensus_verify_script` for the verification status)*
- `CB AI COINconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `CB AI COINconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `CB AI COINconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `CB AI COINconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NCB AI COIN](https://github.com/NicolasDorier/NCB AI COIN/blob/master/NCB AI COIN/Script.cs#L814) (.NET Bindings)
- [node-libCB AI COINconsensus](https://github.com/bitpay/node-libCB AI COINconsensus) (Node.js Bindings)
- [java-libCB AI COINconsensus](https://github.com/dexX7/java-libCB AI COINconsensus) (Java Bindings)
- [CB AI COINconsensus-php](https://github.com/Bit-Wasp/CB AI COINconsensus-php) (PHP Bindings)
