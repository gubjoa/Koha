package Koha::Acquisition::Invoice::Adjustment;

# This file is part of Koha.
#
# Koha is free software; you can redistribute it and/or modify it under the
# terms of the GNU General Public License as published by the Free Software
# Foundation; either version 3 of the License, or (at your option) any later
# version.
#
# Koha is distributed in the hope that it will be useful, but WITHOUT ANY
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
# A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with Koha; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

use Modern::Perl;

use Carp;

use Koha::Database;
use Koha::Acquisition::Invoice;

use base qw(Koha::Object);

=head1 NAME

Koha::Acquisition::Invoice::Adjustment - Koha Invoice Adjustment class

=head1 API

=head2 Class Methods

=cut

=head3 invoice

my $invoice = $adjustment->invoice;

Return the invoice for this adjustment

=cut

sub invoice {
    my ( $self ) = @_;
    my $invoice_rs = $self->_result->invoiceid;
    return Koha::Acquisition::Invoice->_new_from_dbic( $invoice_rs );
}

=head3 type

=cut

sub _type {
    return 'AqinvoiceAdjustment';
}

1;
