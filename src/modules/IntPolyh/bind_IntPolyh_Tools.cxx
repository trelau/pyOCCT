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
#include <Standard_Handle.hxx>
#include <Adaptor3d_HSurface.hxx>
#include <Standard_TypeDef.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <IntPolyh_ArrayOfPointNormal.hxx>
#include <IntPolyh_Tools.hxx>

void bind_IntPolyh_Tools(py::module &mod){

py::class_<IntPolyh_Tools> cls_IntPolyh_Tools(mod, "IntPolyh_Tools", "The class provides tools for surface sampling.");

// Constructors

// Fields

// Methods
cls_IntPolyh_Tools.def_static("IsEnlargePossible_", [](const opencascade::handle<Adaptor3d_HSurface> & theSurf, Standard_Boolean & theUEnlarge, Standard_Boolean & theVEnlarge){ IntPolyh_Tools::IsEnlargePossible(theSurf, theUEnlarge, theVEnlarge); return std::tuple<Standard_Boolean &, Standard_Boolean &>(theUEnlarge, theVEnlarge); }, "Checks if the surface can be enlarged in U or V direction.", py::arg("theSurf"), py::arg("theUEnlarge"), py::arg("theVEnlarge"));
cls_IntPolyh_Tools.def_static("MakeSampling_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const Standard_Integer, const Standard_Integer, const Standard_Boolean, TColStd_Array1OfReal &, TColStd_Array1OfReal &)) &IntPolyh_Tools::MakeSampling, "Makes the sampling of the given surface <theSurf> making the net of <theNbSU> x <theNbSV> sampling points. The flag <theEnlargeZone> controls the enlargement of the sampling zone on the surface. The parameters of the sampling points are stored into <theUPars> and <theVPars> arrays.", py::arg("theSurf"), py::arg("theNbSU"), py::arg("theNbSV"), py::arg("theEnlargeZone"), py::arg("theUPars"), py::arg("theVPars"));
cls_IntPolyh_Tools.def_static("ComputeDeflection_", (Standard_Real (*)(const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &)) &IntPolyh_Tools::ComputeDeflection, "Computes the deflection tolerance on the surface for the given sampling.", py::arg("theSurf"), py::arg("theUPars"), py::arg("theVPars"));
cls_IntPolyh_Tools.def_static("FillArrayOfPointNormal_", (void (*)(const opencascade::handle<Adaptor3d_HSurface> &, const TColStd_Array1OfReal &, const TColStd_Array1OfReal &, IntPolyh_ArrayOfPointNormal &)) &IntPolyh_Tools::FillArrayOfPointNormal, "Fills the array <thePoints> with the points (triangulation nodes) on the surface and normal directions of the surface in these points.", py::arg("theSurf"), py::arg("theUPars"), py::arg("theVPars"), py::arg("thePoints"));

// Enums

}