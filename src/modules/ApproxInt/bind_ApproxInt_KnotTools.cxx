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
#include <Standard.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <math_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Vector.hxx>
#include <NCollection_LocalArray.hxx>
#include <NCollection_Sequence.hxx>
#include <TColStd_Array1OfReal.hxx>
#include <ApproxInt_KnotTools.hxx>

void bind_ApproxInt_KnotTools(py::module &mod){

py::class_<ApproxInt_KnotTools, std::unique_ptr<ApproxInt_KnotTools>> cls_ApproxInt_KnotTools(mod, "ApproxInt_KnotTools", "This class intended to build knots sequence on discrete set of points for further approximation into bspline curve.");

// Constructors

// Fields

// Methods
// cls_ApproxInt_KnotTools.def_static("operator new_", (void * (*)(size_t)) &ApproxInt_KnotTools::operator new, "None", py::arg("theSize"));
// cls_ApproxInt_KnotTools.def_static("operator delete_", (void (*)(void *)) &ApproxInt_KnotTools::operator delete, "None", py::arg("theAddress"));
// cls_ApproxInt_KnotTools.def_static("operator new[]_", (void * (*)(size_t)) &ApproxInt_KnotTools::operator new[], "None", py::arg("theSize"));
// cls_ApproxInt_KnotTools.def_static("operator delete[]_", (void (*)(void *)) &ApproxInt_KnotTools::operator delete[], "None", py::arg("theAddress"));
// cls_ApproxInt_KnotTools.def_static("operator new_", (void * (*)(size_t, void *)) &ApproxInt_KnotTools::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_ApproxInt_KnotTools.def_static("operator delete_", (void (*)(void *, void *)) &ApproxInt_KnotTools::operator delete, "None", py::arg(""), py::arg(""));
cls_ApproxInt_KnotTools.def_static("BuildKnots_", (void (*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const TColgp_Array1OfPnt2d &, const math_Vector &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, NCollection_Vector<Standard_Integer> &)) &ApproxInt_KnotTools::BuildKnots, "Main function to build optimal knot sequence. At least one set from (thePntsXYZ, thePntsU1V1, thePntsU2V2) should exist.", py::arg("thePntsXYZ"), py::arg("thePntsU1V1"), py::arg("thePntsU2V2"), py::arg("thePars"), py::arg("theApproxXYZ"), py::arg("theApproxU1V1"), py::arg("theApproxU2V2"), py::arg("theMinNbPnts"), py::arg("theKnots"));

// Enums

}