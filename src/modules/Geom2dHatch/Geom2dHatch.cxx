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

void bind_Geom2dHatch_Intersector(py::module &);
void bind_Geom2dHatch_FClass2dOfClassifier(py::module &);
void bind_Geom2dHatch_Classifier(py::module &);
void bind_Geom2dHatch_Element(py::module &);
void bind_Geom2dHatch_MapOfElements(py::module &);
void bind_Geom2dHatch_DataMapIteratorOfMapOfElements(py::module &);
void bind_Geom2dHatch_Elements(py::module &);
void bind_Geom2dHatch_Hatching(py::module &);
void bind_Geom2dHatch_Hatchings(py::module &);
void bind_Geom2dHatch_DataMapIteratorOfHatchings(py::module &);
void bind_Geom2dHatch_Hatcher(py::module &);

PYBIND11_MODULE(Geom2dHatch, mod) {

py::module::import("OCCT.Geom2dInt");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2dAdaptor");
py::module::import("OCCT.gp");
py::module::import("OCCT.TopAbs");
py::module::import("OCCT.TopTrans");
py::module::import("OCCT.IntRes2d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.HatchGen");
py::module::import("OCCT.Geom2d");

bind_Geom2dHatch_Intersector(mod);
bind_Geom2dHatch_FClass2dOfClassifier(mod);
bind_Geom2dHatch_Classifier(mod);
bind_Geom2dHatch_Element(mod);
bind_Geom2dHatch_MapOfElements(mod);
bind_Geom2dHatch_DataMapIteratorOfMapOfElements(mod);
bind_Geom2dHatch_Elements(mod);
bind_Geom2dHatch_Hatching(mod);
bind_Geom2dHatch_Hatchings(mod);
bind_Geom2dHatch_DataMapIteratorOfHatchings(mod);
bind_Geom2dHatch_Hatcher(mod);

}
