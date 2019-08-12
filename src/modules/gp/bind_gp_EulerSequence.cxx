/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <gp_EulerSequence.hxx>

void bind_gp_EulerSequence(py::module &mod){

py::enum_<gp_EulerSequence>(mod, "gp_EulerSequence", "Enumerates all 24 possible variants of generalized Euler angles, defining general 3d rotation by three rotations around main axes of coordinate system, in different possible orders.")
	.value("gp_EulerAngles", gp_EulerSequence::gp_EulerAngles)
	.value("gp_YawPitchRoll", gp_EulerSequence::gp_YawPitchRoll)
	.value("gp_Extrinsic_XYZ", gp_EulerSequence::gp_Extrinsic_XYZ)
	.value("gp_Extrinsic_XZY", gp_EulerSequence::gp_Extrinsic_XZY)
	.value("gp_Extrinsic_YZX", gp_EulerSequence::gp_Extrinsic_YZX)
	.value("gp_Extrinsic_YXZ", gp_EulerSequence::gp_Extrinsic_YXZ)
	.value("gp_Extrinsic_ZXY", gp_EulerSequence::gp_Extrinsic_ZXY)
	.value("gp_Extrinsic_ZYX", gp_EulerSequence::gp_Extrinsic_ZYX)
	.value("gp_Intrinsic_XYZ", gp_EulerSequence::gp_Intrinsic_XYZ)
	.value("gp_Intrinsic_XZY", gp_EulerSequence::gp_Intrinsic_XZY)
	.value("gp_Intrinsic_YZX", gp_EulerSequence::gp_Intrinsic_YZX)
	.value("gp_Intrinsic_YXZ", gp_EulerSequence::gp_Intrinsic_YXZ)
	.value("gp_Intrinsic_ZXY", gp_EulerSequence::gp_Intrinsic_ZXY)
	.value("gp_Intrinsic_ZYX", gp_EulerSequence::gp_Intrinsic_ZYX)
	.value("gp_Extrinsic_XYX", gp_EulerSequence::gp_Extrinsic_XYX)
	.value("gp_Extrinsic_XZX", gp_EulerSequence::gp_Extrinsic_XZX)
	.value("gp_Extrinsic_YZY", gp_EulerSequence::gp_Extrinsic_YZY)
	.value("gp_Extrinsic_YXY", gp_EulerSequence::gp_Extrinsic_YXY)
	.value("gp_Extrinsic_ZYZ", gp_EulerSequence::gp_Extrinsic_ZYZ)
	.value("gp_Extrinsic_ZXZ", gp_EulerSequence::gp_Extrinsic_ZXZ)
	.value("gp_Intrinsic_XYX", gp_EulerSequence::gp_Intrinsic_XYX)
	.value("gp_Intrinsic_XZX", gp_EulerSequence::gp_Intrinsic_XZX)
	.value("gp_Intrinsic_YZY", gp_EulerSequence::gp_Intrinsic_YZY)
	.value("gp_Intrinsic_YXY", gp_EulerSequence::gp_Intrinsic_YXY)
	.value("gp_Intrinsic_ZXZ", gp_EulerSequence::gp_Intrinsic_ZXZ)
	.value("gp_Intrinsic_ZYZ", gp_EulerSequence::gp_Intrinsic_ZYZ)
	.export_values();


}