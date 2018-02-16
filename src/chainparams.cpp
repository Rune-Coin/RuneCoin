// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2016 The runecoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"

#include "assert.h"
#include "core.h"
#include "protocol.h"
#include "util.h"
#include "scrypt.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

//
// Main network
//

unsigned int pnSeed[] =
{
    0xA2F39055, 0x5EF2E56F, 0x57D54ADA, 0x50F812B0, 0x256187D5, 0x9FCBD468, 0x92B9AB35, 0x8AC586B4
};

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        pchMessageStart[0] = 0xfd;
        pchMessageStart[1] = 0xa4;
        pchMessageStart[2] = 0xdc;
        pchMessageStart[3] = 0x6c;
        vAlertPubKey = ParseHex("04d1832d7d0c59634d67d3023379403014c2878d0c2372d175219063a48fa06e6d429e09f36d3196ec544c2cfdd12d6fe510a399595f75ebb6da238eb5f70f2072");
        nDefaultPort = 12340;
        nRPCPort = 12341;

        bnProofOfWorkLimit[ALGO_SHA256D] = CBigNum(~uint256(0) >> 20); // 1.00000000
        bnProofOfWorkLimit[ALGO_SCRYPT]  = CBigNum(~uint256(0) >> 20);
        bnProofOfWorkLimit[ALGO_GROESTL] = CBigNum(~uint256(0) >> 20); // 0.00195311
        bnProofOfWorkLimit[ALGO_SKEIN]   = CBigNum(~uint256(0) >> 20); // 0.00195311
        bnProofOfWorkLimit[ALGO_QUBIT]   = CBigNum(~uint256(0) >> 20); // 0.00097655

        // Build the genesis block.
        const char* pszTimestamp = "Travell the world in 90 days!!! 23/01/2018";
        CTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CBigNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04a5814813115273a109cff99907ba4a05d951873dae7acb6c973d0c9e7c88911a3dbc9aa600deac241b91707e7b4ffb30ad91c8e56e695a1ddf318592988afe0a") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1390598806;
        genesis.nBits    = Params().ProofOfWorkLimit(ALGO_SCRYPT).GetCompact();
        //genesis.nBits = 0x1e0fffff;
        genesis.nNonce   = 378414;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x130b85d6e94f15fd102507108c0afcee275fdb39c9046ea86dfbe7a7810a4c6f"));
        assert(genesis.hashMerkleRoot == uint256("0xd7b7f0c59f4ee9d29fd9fbe445bc4789887c2d83aa860190a1762dbe068940ea"));

        vSeeds.push_back(CDNSSeedData("runecoin.co", "runecoin.co"));
//        vSeeds.push_back(CDNSSeedData("united-states-west", "RUNEseed1.criptoe.com"));
//        vSeeds.push_back(CDNSSeedData("united-states-east", "s1.RUNEoraseed.com"));
//        vSeeds.push_back(CDNSSeedData("iceland", "s1.RUNEoraseed.org"));
//        vSeeds.push_back(CDNSSeedData("the-netherlands", "s1.RUNEoraseed.eu"));
//        vSeeds.push_back(CDNSSeedData("electrum2", "electrum2.RUNEorcoin.is"));
//        vSeeds.push_back(CDNSSeedData("electrum3", "electrum3.runecoin.is"));
//        vSeeds.push_back(CDNSSeedData("electrum4", "electrum4.runecoin.is"));

        base58Prefixes[PUBKEY_ADDRESS] = list_of(23);
        base58Prefixes[SCRIPT_ADDRESS] = list_of(5);
        base58Prefixes[SECRET_KEY]     = list_of(176);
        base58Prefixes[SECRET_KEY_OLD] = list_of(151);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0xB2)(0x1E);
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0xAD)(0xE4);
        // Convert the pnSeeds array into usable address objects.
        for (unsigned int i = 0; i < ARRAYLEN(pnSeed); i++)
        {
            const int64_t nOneWeek = 7*24*60*60;
            struct in_addr ip;
            memcpy(&ip, &pnSeed[i], sizeof(ip));
            CAddress addr(CService(ip, GetDefaultPort()));
            addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
            vFixedSeeds.push_back(addr);
        }
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {

    SelectParams(CChainParams::MAIN);
    return true;
}
