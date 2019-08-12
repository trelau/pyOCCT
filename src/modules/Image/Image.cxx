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

void bind_Image_Format(py::module &);
void bind_Image_ColorRGB(py::module &);
void bind_Image_ColorRGB32(py::module &);
void bind_Image_ColorRGBA(py::module &);
void bind_Image_ColorBGR(py::module &);
void bind_Image_ColorBGR32(py::module &);
void bind_Image_ColorBGRA(py::module &);
void bind_Image_ColorRGBF(py::module &);
void bind_Image_ColorBGRF(py::module &);
void bind_Image_ColorRGBAF(py::module &);
void bind_Image_ColorBGRAF(py::module &);
void bind_Image_PixMapData(py::module &);
void bind_Image_PixMap(py::module &);
void bind_Image_AlienPixMap(py::module &);
void bind_Image_Diff(py::module &);
void bind_Image_VideoParams(py::module &);
void bind_Image_VideoRecorder(py::module &);

PYBIND11_MODULE(Image, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Resource");

bind_Image_Format(mod);
bind_Image_ColorRGB(mod);
bind_Image_ColorRGB32(mod);
bind_Image_ColorRGBA(mod);
bind_Image_ColorBGR(mod);
bind_Image_ColorBGR32(mod);
bind_Image_ColorBGRA(mod);
bind_Image_ColorRGBF(mod);
bind_Image_ColorBGRF(mod);
bind_Image_ColorRGBAF(mod);
bind_Image_ColorBGRAF(mod);
bind_Image_PixMapData(mod);
bind_Image_PixMap(mod);
bind_Image_AlienPixMap(mod);
bind_Image_Diff(mod);
bind_Image_VideoParams(mod);
bind_Image_VideoRecorder(mod);

}
