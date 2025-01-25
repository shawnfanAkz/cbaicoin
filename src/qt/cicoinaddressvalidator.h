// Copyright (c) 2011-2014 The CB AI COIN Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_BITCOINADDRESSVALIDATOR_H
#define BITCOIN_QT_BITCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class CB AI COINAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CB AI COINAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** CB AI COIN address widget validator, checks for a valid CB AI COIN address.
 */
class CB AI COINAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CB AI COINAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BITCOIN_QT_BITCOINADDRESSVALIDATOR_H
