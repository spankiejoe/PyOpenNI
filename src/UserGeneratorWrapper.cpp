/* ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This file is part of PyOpenNI.
 *
 * PyOpenNI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PyOpenNI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with PyOpenNI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * PyOpenNI is Copyright (C) 2011, Xavier Mendez (jmendeth).
 * OpenNI Python Wrapper (ONIPY) is Copyright (C) 2011, Gabriele Nataneli (gamix).
 *
 * ***** END GPL LICENSE BLOCK ***** */


#include "UserGeneratorWrapper.h"

#include <XnCppWrapper.h>
#include "wrapperTypes.h"
#include "wrapperExceptions.h"

void UserGenerator_Create_wrapped(xn::UserGenerator& self, xn::Context& ctx) {
    check( self.Create(ctx, NULL, NULL) );
}

XnUInt16 UserGenerator_CountUsers(xn::UserGenerator const & self) {
    checkValid(self);
    
    return self.GetNumberOfUsers();
}

xn::SkeletonCapability UserGenerator_GetSkeletonCap_wrapped(xn::UserGenerator& self) {
    checkValid(self);
    
    if (!self.IsCapabilitySupported(XN_CAPABILITY_SKELETON)) {
        return NULL;
    }
    
    return self.GetSkeletonCap();
}
