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

void bind_Geom2dInt_TheIntConicCurveOfGInter(py::module &);
void bind_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter(py::module &);
void bind_Geom2dInt_TheIntPCurvePCurveOfGInter(py::module &);
void bind_Geom2dInt_GInter(py::module &);
void bind_Geom2dInt_IntConicCurveOfGInter(py::module &);
void bind_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter(py::module &);
void bind_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter(py::module &);
void bind_Geom2dInt_Geom2dCurveTool(py::module &);
void bind_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter(py::module &);
void bind_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter(py::module &);
void bind_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter(py::module &);
void bind_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter(py::module &);
void bind_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter(py::module &);
void bind_Geom2dInt_TheProjPCurOfGInter(py::module &);

PYBIND11_MODULE(Geom2dInt, mod) {

py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.Standard");
py::module::import("OCCT.gp");
py::module::import("OCCT.Adaptor2d");
py::module::import("OCCT.IntCurve");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.math");
py::module::import("OCCT.GeomAbs");
py::module::import("OCCT.Extrema");
py::module::import("OCCT.Intf");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.TColgp");

bind_Geom2dInt_TheIntConicCurveOfGInter(mod);
bind_Geom2dInt_TheIntersectorOfTheIntConicCurveOfGInter(mod);
bind_Geom2dInt_TheIntPCurvePCurveOfGInter(mod);
bind_Geom2dInt_GInter(mod);
bind_Geom2dInt_IntConicCurveOfGInter(mod);
bind_Geom2dInt_TheDistBetweenPCurvesOfTheIntPCurvePCurveOfGInter(mod);
bind_Geom2dInt_ExactIntersectionPointOfTheIntPCurvePCurveOfGInter(mod);
bind_Geom2dInt_Geom2dCurveTool(mod);
bind_Geom2dInt_MyImpParToolOfTheIntersectorOfTheIntConicCurveOfGInter(mod);
bind_Geom2dInt_PCLocFOfTheLocateExtPCOfTheProjPCurOfGInter(mod);
bind_Geom2dInt_TheCurveLocatorOfTheProjPCurOfGInter(mod);
bind_Geom2dInt_TheLocateExtPCOfTheProjPCurOfGInter(mod);
bind_Geom2dInt_ThePolygon2dOfTheIntPCurvePCurveOfGInter(mod);
bind_Geom2dInt_TheProjPCurOfGInter(mod);

}
