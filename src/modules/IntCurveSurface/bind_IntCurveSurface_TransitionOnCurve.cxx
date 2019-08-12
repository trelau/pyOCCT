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
#include <IntCurveSurface_TransitionOnCurve.hxx>

void bind_IntCurveSurface_TransitionOnCurve(py::module &mod){

py::enum_<IntCurveSurface_TransitionOnCurve>(mod, "IntCurveSurface_TransitionOnCurve", "\ Uo ^ \ U1 ^ \ | n \ | n Surf ====\======|=== ====\======|=== \ . \ . \ . \ . U1 \ . Uo \ .")
	.value("IntCurveSurface_Tangent", IntCurveSurface_TransitionOnCurve::IntCurveSurface_Tangent)
	.value("IntCurveSurface_In", IntCurveSurface_TransitionOnCurve::IntCurveSurface_In)
	.value("IntCurveSurface_Out", IntCurveSurface_TransitionOnCurve::IntCurveSurface_Out)
	.export_values();


}