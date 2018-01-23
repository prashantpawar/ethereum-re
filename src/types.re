type blockTag = [ | `latest | `earliest | `pending | `blockNumber(string)];

type rpcVersion = [ | `two_zero];

type connection = {
  endpoint: string,
  rpcVersion
};

module JSONRPC = {
  type error('a) = {
    code: int,
    message: string,
    data: option('a)
  };
  type response('a, 'b) = {
    jsonrpc: string,
    result: option('a),
    error: option(error('b)),
    id: string
  };
};

type networkId =
  | EthereumMainnet
  | MordenTestnetDeprecated
  | RopstenTestnet
  | RinkebyTestnet
  | KovanTestnet;

type transaction = {
  from: option(string),
  to_: option(string),
  gas: option(string),
  gasPrice: option(string),
  value: option(string),
  data: option(string)
};

type block = {
  number: option(string),
  hash: option(string),
  parentHash: string,
  nonce: option(string),
  sha3Uncles: string,
  logsBloom: option(string),
  transactionsRoot: string,
  stateRoot: string,
  receiptsRoot: string,
  miner: string,
  difficulty: string,
  totalDifficulty: string,
  extraData: string,
  size: string,
  gasLimit: string,
  gasUsed: string,
  timestamp: string,
  transactions: [ | `transactions(array(transaction)) | `hashes(array(string))],
  uncles: array(string)
};
