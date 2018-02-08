/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <TColgp_Array1OfPnt.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <math_Vector.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_Vector.hxx>
#include <ApproxInt_KnotTools.hxx>
#include <gp_Pnt.hxx>
#include <gp_Vec.hxx>
#include <gp_Vec2d.hxx>
#include <IntSurf_PntOn2S.hxx>
#include <ApproxInt_SvSurfaces.hxx>

PYBIND11_MODULE(ApproxInt, mod) {

	// IMPORT
	py::module::import("OCCT.TColgp");
	py::module::import("OCCT.math");
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.IntSurf");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\ApproxInt_KnotTools.hxx
	py::class_<ApproxInt_KnotTools, std::unique_ptr<ApproxInt_KnotTools, Deleter<ApproxInt_KnotTools>>> cls_ApproxInt_KnotTools(mod, "ApproxInt_KnotTools", "This class intended to build knots sequence on discrete set of points for further approximation into bspline curve.");
	cls_ApproxInt_KnotTools.def(py::init<>());
	cls_ApproxInt_KnotTools.def_static("BuildKnots_", (void (*)(const TColgp_Array1OfPnt &, const TColgp_Array1OfPnt2d &, const TColgp_Array1OfPnt2d &, const math_Vector &, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean, const Standard_Integer, NCollection_Vector<Standard_Integer> &)) &ApproxInt_KnotTools::BuildKnots, "Main function to build optimal knot sequence. At least one set from (thePntsXYZ, thePntsU1V1, thePntsU2V2) should exist.", py::arg("thePntsXYZ"), py::arg("thePntsU1V1"), py::arg("thePntsU2V2"), py::arg("thePars"), py::arg("theApproxXYZ"), py::arg("theApproxU1V1"), py::arg("theApproxU2V2"), py::arg("theMinNbPnts"), py::arg("theKnots"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\ApproxInt_SvSurfaces.hxx
	py::class_<ApproxInt_SvSurfaces, std::unique_ptr<ApproxInt_SvSurfaces, Deleter<ApproxInt_SvSurfaces>>> cls_ApproxInt_SvSurfaces(mod, "ApproxInt_SvSurfaces", "None");
	cls_ApproxInt_SvSurfaces.def("Compute", [](ApproxInt_SvSurfaces &self, Standard_Real & u1, Standard_Real & v1, Standard_Real & u2, Standard_Real & v2, gp_Pnt & Pt, gp_Vec & Tg, gp_Vec2d & Tguv1, gp_Vec2d & Tguv2){ Standard_Boolean rv = self.Compute(u1, v1, u2, v2, Pt, Tg, Tguv1, Tguv2); return std::tuple<Standard_Boolean, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(rv, u1, v1, u2, v2); }, "returns True if Tg,Tguv1 Tguv2 can be computed.", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Pt"), py::arg("Tg"), py::arg("Tguv1"), py::arg("Tguv2"));
	cls_ApproxInt_SvSurfaces.def("Pnt", (void (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Pnt &)) &ApproxInt_SvSurfaces::Pnt, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("P"));
	cls_ApproxInt_SvSurfaces.def("SeekPoint", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, IntSurf_PntOn2S &)) &ApproxInt_SvSurfaces::SeekPoint, "computes point on curve and parameters on the surfaces", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Point"));
	cls_ApproxInt_SvSurfaces.def("Tangency", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec &)) &ApproxInt_SvSurfaces::Tangency, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
	cls_ApproxInt_SvSurfaces.def("TangencyOnSurf1", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &ApproxInt_SvSurfaces::TangencyOnSurf1, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));
	cls_ApproxInt_SvSurfaces.def("TangencyOnSurf2", (Standard_Boolean (ApproxInt_SvSurfaces::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, gp_Vec2d &)) &ApproxInt_SvSurfaces::TangencyOnSurf2, "None", py::arg("u1"), py::arg("v1"), py::arg("u2"), py::arg("v2"), py::arg("Tg"));


}
