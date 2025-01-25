// Copyright (c) 2011-2014 The CI AI COIN Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_BITCOINADDRESSVALIDATOR_H
#define BITCOIN_QT_BITCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class CI AI COINAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CI AI COINAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** CI AI COIN address widget validator, checks for a valid CI AI COIN address.
 */
class CI AI COINAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit CI AI COINAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BITCOIN_QT_BITCOINADDRESSVALIDATOR_H
