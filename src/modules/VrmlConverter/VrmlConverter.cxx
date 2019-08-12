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

void bind_VrmlConverter_TypeOfCamera(py::module &);
void bind_VrmlConverter_TypeOfLight(py::module &);
void bind_VrmlConverter_Curve(py::module &);
void bind_VrmlConverter_DeflectionCurve(py::module &);
void bind_VrmlConverter_Drawer(py::module &);
void bind_VrmlConverter_HLRShape(py::module &);
void bind_VrmlConverter_LineAspect(py::module &);
void bind_VrmlConverter_IsoAspect(py::module &);
void bind_VrmlConverter_PointAspect(py::module &);
void bind_VrmlConverter_Projector(py::module &);
void bind_VrmlConverter_ShadedShape(py::module &);
void bind_VrmlConverter_ShadingAspect(py::module &);
void bind_VrmlConverter_WFDeflectionRestrictedFace(py::module &);
void bind_VrmlConverter_WFDeflectionShape(py::module &);
void bind_VrmlConverter_WFRestrictedFace(py::module &);
void bind_VrmlConverter_WFShape(py::module &);

PYBIND11_MODULE(VrmlConverter, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Adaptor3d");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.TopoDS");
py::module::import("OCCT.Vrml");
py::module::import("OCCT.TopTools");
py::module::import("OCCT.HLRAlgo");
py::module::import("OCCT.Poly");
py::module::import("OCCT.TColgp");
py::module::import("OCCT.BRepAdaptor");

bind_VrmlConverter_TypeOfCamera(mod);
bind_VrmlConverter_TypeOfLight(mod);
bind_VrmlConverter_Curve(mod);
bind_VrmlConverter_DeflectionCurve(mod);
bind_VrmlConverter_Drawer(mod);
bind_VrmlConverter_HLRShape(mod);
bind_VrmlConverter_LineAspect(mod);
bind_VrmlConverter_IsoAspect(mod);
bind_VrmlConverter_PointAspect(mod);
bind_VrmlConverter_Projector(mod);
bind_VrmlConverter_ShadedShape(mod);
bind_VrmlConverter_ShadingAspect(mod);
bind_VrmlConverter_WFDeflectionRestrictedFace(mod);
bind_VrmlConverter_WFDeflectionShape(mod);
bind_VrmlConverter_WFRestrictedFace(mod);
bind_VrmlConverter_WFShape(mod);

}
