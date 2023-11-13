#include "rpmcontrol.h"

#include <QTimer>

const constexpr int MAX_RPM = 8000;

RPMControl::RPMControl( QObject* parent ) :
    QObject( parent ),
    _RPMCount( 0 ) {}

void RPMControl::doStart() {
    for ( int i = 0; i < ( MAX_RPM + 1 ); i++ ) {
        QTimer::singleShot( 1000 * i, this, [i, this] {
            int rpmFinal = i * 1000;
            if ( rpmFinal < MAX_RPM ) {
                setRPMCount( i * 1000 );
            }

        } );
    }
}

int RPMControl::RPMCount() {
    return _RPMCount;
}

void RPMControl::setRPMCount( const int RPMCount ) {
    _RPMCount = RPMCount;
    emit RPMCountChanged();
}
