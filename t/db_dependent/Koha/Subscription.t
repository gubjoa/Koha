#!/usr/bin/perl

# Copyright 2016 Koha Development team
#
# This file is part of Koha
#
# Koha is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# Koha is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Koha; if not, see <http://www.gnu.org/licenses>.

use Modern::Perl;

use Test::More tests => 1;

use Koha::Subscription;
use Koha::Biblio;

my $schema = Koha::Database->new->schema;
$schema->storage->txn_begin;

subtest 'Koha::Subscription::biblio' => sub {
    plan tests => 1;

    my $biblio = Koha::Biblio->new()->store();
    my $subscription = Koha::Subscription->new({
        biblionumber => $biblio->biblionumber,
    })->store();

    my $b = $subscription->biblio;
    is($b->biblionumber, $biblio->biblionumber, 'Koha::Subscription::biblio returns the correct biblio');
};

$schema->storage->txn_rollback;

1;
